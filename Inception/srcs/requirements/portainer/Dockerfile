FROM alpine:3.17

RUN apk update && apk upgrade && apk add wget

RUN wget https://github.com/portainer/portainer/releases/download/2.19.1/portainer-2.19.1-linux-amd64.tar.gz -O portainer.tar.gz

RUN tar -xf portainer.tar.gz

WORKDIR /portainer

RUN chmod 777 portainer

ENTRYPOINT [ "./portainer" ]
