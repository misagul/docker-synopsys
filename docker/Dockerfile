FROM centos:6.10

COPY CentOS-6-Vault-BFSU.repo /etc/yum.repos.d/CentOS-Base.repo
COPY snpslmd-hack.c /root/snpslmd-hack.c
COPY Synopsys /opt/Synopsys

RUN yum -y update
RUN yum -y install gcc wget
RUN gcc -ldl -shared -fPIC /root/snpslmd-hack.c -o /root/snpslmd-hack.so
RUN mkdir /root/glibc217
WORKDIR /root/glibc217
RUN wget http://ftp.gnu.org/gnu/glibc/glibc-2.17.tar.gz
RUN tar -zxvf glibc-2.17.tar.gz
WORKDIR /root/glibc217/glibc-2.17
RUN mkdir build
RUN cd /root/glibc217/glibc-2.17/build && \
    ../configure --prefix=/root/.local
WORKDIR /root/glibc217/glibc-2.17/build
RUN make -j4
RUN touch /root/.local/etc/ld.so.conf
RUN make install

ENV LD_LIBRARY_PATH=/root/.local/lib
ENV PATH=$PATH:/opt/Synopsys/scl/bin
ENV LD_PRELOAD=/root/snpslmd-hack.so

CMD /bin/bash
