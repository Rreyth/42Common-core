#!/bin/sh

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld


chown -R mysql:mysql /var/lib/mysql

mysql_install_db --user=mysql --ldata=/var/lib/mysql > /dev/null


tfile=`mktemp`
if [ ! -f "$tfile" ]; then
    return 1
fi

cat << EOF > $tfile
USE mysql;
FLUSH PRIVILEGES ;
GRANT ALL ON *.* TO 'root'@'%' identified by '$MARIADB_ROOT_PWD' WITH GRANT OPTION ;
GRANT ALL ON *.* TO 'root'@'localhost' identified by '$MARIADB_ROOT_PWD' WITH GRANT OPTION ;
SET PASSWORD FOR 'root'@'localhost'=PASSWORD('${MARIADB_ROOT_PWD}') ;
DROP DATABASE IF EXISTS test ;
FLUSH PRIVILEGES ;
EOF

if [ "$MARIADB_DB" != "" ]; then
	echo "CREATE DATABASE IF NOT EXISTS \`$MARIADB_DB\` CHARACTER SET utf8 COLLATE utf8_general_ci;" >> $tfile

	if [ "$MARIADB_USER" != "" ]; then
		echo "GRANT ALL ON \`$MARIADB_DB\`.* to '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PWD';" >> $tfile
	fi
fi

/usr/bin/mysqld --user=mysql --bootstrap --verbose=0 --skip-name-resolve --skip-networking=0 < $tfile
rm -f $tfile

exec /usr/bin/mysqld --user=mysql --console --skip-name-resolve --skip-networking=0 $@
