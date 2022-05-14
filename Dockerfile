# Build Stage
FROM --platform=linux/amd64 ubuntu:20.04 as builder

## Install build dependencies.
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y vim less man wget tar git gzip unzip make cmake software-properties-common curl
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y gperf
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends erlang
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y elixir
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y clang
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libz-dev

ADD . /repo
WORKDIR /repo/build
RUN cmake ..
RUN make -j8
