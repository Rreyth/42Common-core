FROM alpine:3.17

RUN apk update
RUN apk upgrade
RUN apk add mariadb mariadb-client mariadb-server-utils
RUN rm -f /var/cache/apk/*

RUN rm -rf /etc/my.cnf.d/mariadb-server.cnf
COPY conf/my.cnf /etc/my.cnf.d/mariadb-server.cnf

COPY tools/start.sh .
RUN chmod +x start.sh

EXPOSE 3306

ENTRYPOINT [ "./start.sh" ]
