docker rm -f scl || true
docker run -it --name=scl --hostname=libero --mac-address="" -v /opt/Synopsys:/opt/Synopsys scl
