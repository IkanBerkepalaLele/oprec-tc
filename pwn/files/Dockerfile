# docker build -t pwn .
# docker run -d -p 4321:4321 --rm pwn

# build
FROM ubuntu:18.04 AS builder

RUN apt-get update && apt-get install -y g++

WORKDIR /build
COPY gema.cpp .

RUN g++ -o gema gema.cpp

#run
FROM ubuntu:18.04

ENV user=compfest18
ENV chall_port=4321

RUN apt-get update \
    && apt-get install -y socat \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -m $user

WORKDIR /home/$user

COPY --from=builder /build/gema /home/$user/gema
COPY run.sh         /run.sh
COPY flag.txt       /home/$user/flag.txt

RUN chown root:$user    /home/$user/gema
RUN chown $user:$user   /home/$user/flag.txt
RUN chown root:$user    /home/$user

RUN chmod 755           /home/$user
RUN chmod 750           /home/$user/gema
RUN chmod +x /run.sh

USER $user
EXPOSE $chall_port
ENTRYPOINT ["/run.sh"]