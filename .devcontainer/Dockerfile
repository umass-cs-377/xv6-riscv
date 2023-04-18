FROM ubuntu:latest

# RUN apt-get -qq update && \
#     apt-get install -yq tzdata && \
#     ln -fs /usr/share/zoneinfo/America/New_York /etc/localtime && \
#     dpkg-reconfigure -f noninteractive tzdata

# RUN apt-get install -y \
#                     build-essential \
#                     gdb \
#                     gcc-multilib-x86-64-linux-gnu \
#                     tmux \
#                     qemu-system-x86 \
#                     gawk \
#                     expect

# #ADD ./xv6-public /xv6-public

# #WORKDIR /xv6

# ENV TOOLPREFIX=x86_64-linux-gnu-

RUN apt-get -qq update && apt-get -y install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu 

CMD ["/bin/bash"]