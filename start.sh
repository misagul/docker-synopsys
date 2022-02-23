docker rm -f scl || true
docker run -d --name=scl --network=host -v /opt/Synopsys:/opt/Synopsys scl
