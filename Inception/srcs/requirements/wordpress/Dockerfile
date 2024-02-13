FROM alpine:3.17

RUN apk update
RUN apk upgrade
RUN apk add php81 php81-fpm php81-mysqli php81-gd php81-common php81-curl php81-phar php81-cli php81-mbstring
RUN apk add curl
RUN apk add mariadb-client
RUN apk add fcgi php81-cgi php81-tokenizer
RUN rm -rf /var/cache/apk/*

COPY --chmod=777 conf/www.conf /etc/php81/php-fpm.d/www.conf

RUN mkdir -p /var/www/html
RUN adduser -D -S -G www-data www-data
RUN chmod 777 -R /var/www/html
RUN chown -R www-data:www-data /var/www/html

COPY --chmod=777 tools/start.sh .

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv -f wp-cli.phar /usr/local/bin/wp

EXPOSE 9000

ENTRYPOINT [ "./start.sh" ]
