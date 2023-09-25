FROM ubuntu:22.04

RUN apt-get update
RUN apt install -y tzdata

RUN mkdir /src

RUN apt install -y wget \
    g++ \
    cmake \
    git \
    clang-format \
    libmysqlcppconn-dev 
    # boost

ENV LD_LIBRARY_PATH /usr/lib/x86_64-linux-gnu
ENV CFLAGS -m64
ENV CXXFLAGS -m64
ENV TZ=Asia/Tokyo