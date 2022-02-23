DOCKER_BUILDKIT=1

all: scl synopsys
scl:
	docker build . -f Dockerfile.scl -t scl
synopsys:
	docker build . -f Dockerfile.synopsys -t synopsys
