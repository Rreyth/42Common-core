FROM alpine:3.17

RUN apk update
RUN apk upgrade
RUN apk add nginx
RUN mkdir -p /var/www/html/

RUN mkdir -p /etc/nginx/ssl
RUN apk add openssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/L=Angouleme/O=42/OU=tdhaussy/CN=tdhaussy.42.fr"
RUN mkdir -p /var/run/nginx

RUN adduser -D -S -G www-data www-data
RUN chown -R www-data:www-data /var/www/html

COPY --chmod=777 --chown=www-data conf/nginx.conf /etc/nginx/.
COPY tools/static.html /var/www/html/static.html

EXPOSE 443

ENTRYPOINT [ "/usr/sbin/nginx", "-g", "daemon off;" ]
