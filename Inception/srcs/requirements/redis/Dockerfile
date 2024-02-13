FROM alpine:3.17

RUN apk update && apk upgrade && apk add redis

ENTRYPOINT [ "/usr/bin/redis-server","--protected-mode","no" ]
