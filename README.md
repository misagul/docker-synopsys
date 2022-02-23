# Docker Synopsys

Run Synopsys VCS in Docker.

This would be useful in an shared environment for students to debug and simulate their Verilog code.

# Deployment

Install Docker and clone this repo to `/opt/docker-synopsys`.

You should have Synopsys SCL and VCS in `/opt/Synopsys`. The following directory structure is expected:

```plain
root@cpu:/opt# ls -lah /opt/Synopsys/*
/opt/Synopsys/scl:
total 72K
drwxr-xr-x 3 root root 4.0K Dec 17 11:46 .
drwxr-xr-x 5 root root 4.0K Dec 17 11:46 ..
drwxr-xr-x 3 root root 4.0K Dec 17 11:46 bin
-rw-r--r-- 1 root root  60K Dec 17 11:46 synopsys.dat

/opt/Synopsys/VCS:
total 448K
drwxr-xr-x 13 root root  270 Sep 18 05:10 .
drwxr-xr-x  5 root root 4.0K Dec 17 11:46 ..
drwxr-xr-x  3 root root   46 Sep 18 05:10 admin
lrwxrwxrwx  1 root root    9 Sep 18 05:10 amd64 -> ./linux64
drwxr-xr-x  6 root root 3.4K Sep 18 05:10 bin
drwxr-xr-x  6 root root  298 Sep 18 05:10 doc
drwxr-xr-x 49 root root  973 Sep 18 05:10 etc
drwxr-xr-x  4 root root   56 Sep 18 05:10 gui
drwxr-xr-x  9 root root 1.7K Sep 18 05:10 include
-rw-r--r--  1 root root 2.0M Sep 18 05:10 install.log
drwxr-xr-x  7 root root  132 Sep 18 05:10 linux64
drwxr-xr-x  3 root root  610 Sep 18 05:10 mmc
drwxr-xr-x 17 root root  304 Sep 18 05:10 packages
lrwxrwxrwx  1 root root    9 Sep 18 05:10 suse64 -> ./linux64
drwxr-xr-x  4 root root   62 Sep 18 05:10 vgcommon
drwxr-xr-x  3 root root   46 Sep 18 05:10 vms

/opt/Synopsys/Verdi:
total 440K
drwxr-xr-x  9 root root  189 Sep 18 05:13 .
drwxr-xr-x  5 root root 4.0K Dec 17 11:46 ..
drwxr-xr-x  2 root root   27 Sep 18 05:13 admin
drwxr-xr-x  3 root root 3.3K Sep 18 05:13 bin
drwxr-xr-x 25 root root  681 Sep 18 05:13 etc
drwxr-xr-x  3 root root  442 Sep 18 05:13 font
-rw-r--r--  1 root root 2.2M Sep 18 05:13 install.log
drwxr-xr-x  3 root root  176 Sep 18 05:13 platform
-rw-r--r--  1 root root  409 Sep 18 05:13 README.TXT
drwxr-xr-x  5 root root   86 Sep 18 05:13 share
drwxr-xr-x  2 root root  13K Sep 18 05:13 XFont
```

Your license file should be put in `/opt/Synopsys/synopsys.dat`. The hostname and MAC address of your license should match your host's, or maybe you need to append a `--hostname <hostname>` argument in `start.sh`.

Then build the Docker images and launcher program (to allow normal users run that specfied Docker images, for security):

```bash
# In /opt/docker-synopsys/docker
docker buildx build . -f Dockerfile.scl -t scl
docker buildx build . -f Dockerfile.synopsys -t synopsys

# In /opt/docker-synopsys/cli
make
```

# Usage

On your host startup, start the Synopsys SCL licensing server with `/opt/docker-synopsys/start.sh`.

Append `export PATH=/opt/docker-synopsys/bin:$PATH` to your `/etc/profile` to enable users to use commands we provided. Then `vcs` will be available system-wide. Docker will mount the user's home directory into created container so it's just like using VCS on the host.

You may also check [VCS-Example](https://github.com/t123yh/VCS-Example) for starting a project with VCS.
