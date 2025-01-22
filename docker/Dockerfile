FROM centos:7

COPY CentOS-6-Vault-BFSU.repo /etc/yum.repos.d/CentOS-Base.repo
COPY snpslmd-hack.c /root/snpslmd-hack.c
COPY Synopsys /opt/Synopsys

RUN yum -y update
RUN yum -y install gcc wget
RUN gcc -ldl -shared -fPIC /root/snpslmd-hack.c -o /root/snpslmd-hack.so

CMD /bin/bash
