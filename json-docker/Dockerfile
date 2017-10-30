FROM alpine:3.6 as build

RUN apk add --no-cache make g++ cmake py-pip

RUN pip install --upgrade conan

COPY conanfile.txt CMakeLists.txt main.cpp /src/

RUN mkdir -p /src/build \
    && cd /src/build \
    && conan install .. \
    && cmake .. \
    && make

#---

FROM alpine:3.6
COPY --from=build /usr/lib/libstdc++.so.6 /usr/lib/
COPY --from=build /usr/lib/libgcc_s.so.1 /usr/lib/

COPY --from=build /src/build/bin/hello /example/

WORKDIR /example
CMD ["./hello"]
