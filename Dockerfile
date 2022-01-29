# Image basée sur Turing.unistra.fr pour accélérer la pipeline.
FROM ubuntu:20.04

# Problème des timezones....
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Paris
RUN echo $TZ > /etc/timezone && \
    apt-get update && apt-get install -y tzdata && \
    rm /etc/localtime && \
    ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && \
    dpkg-reconfigure -f noninteractive tzdata && \
    apt-get clean

# Compilation
RUN apt update -y && apt install -y make autoconf gcc flex bison ruby gem python python3-pip lcov wget doxygen tree spim

RUN pip install lcov_cobertura

# Génération de documentation
RUN gem install asciidoctor asciidoctor-pdf --pre
