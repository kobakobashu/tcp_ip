FROM ubuntu:20.04

ARG BRANCH_OR_TAG=main
ARG CMAKE_OPTIONS=
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -qq && apt-get install -y \
    build-essential \
    cmake \
    git \
    g++ \
    iproute2 \
    iputils-ping \
    netcat-openbsd \
    make \
    vim \
    sudo \
    tmux && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* && \
    rm -rf /var/cache/apk/*

# install google test
RUN git clone --depth=1 -b $BRANCH_OR_TAG -q https://github.com/google/googletest.git /googletest
RUN mkdir -p /googletest/build
WORKDIR /googletest/build
RUN cmake .. ${CMAKE_OPTIONS} && make && make install
ENV WORK_PATH /workspace
WORKDIR $WORK_PATH
RUN rm -rf /googletest
