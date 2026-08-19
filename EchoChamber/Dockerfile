FROM debian:bookworm-slim

RUN apt-get update && \
    apt-get install -y --no-install-recommends openssh-server && \
    rm -rf /var/lib/apt/lists/*

COPY EchoChamber flag.txt run.sh /home/ctf/
RUN chmod +x /home/ctf/EchoChamber && \
    chmod +r /home/ctf/flag.txt && \
    useradd -ms /bin/bash ctf && \
    chown -R root:root /home/ctf && \
    passwd -d ctf

RUN mkdir -p /var/run/sshd \
    && ssh-keygen -A
RUN sed -i \
    -e "s/#PasswordAuthentication yes/PasswordAuthentication yes/" \
    -e 's/^#PermitEmptyPasswords no/PermitEmptyPasswords yes/' \
     /etc/ssh/sshd_config

RUN chmod +755 /home/ctf/run.sh

RUN printf "%s\n" \
    "Match User ctf" \
    "   ForceCommand /home/ctf/run.sh" \
    "   DisableForwarding yes" \
    "   PermitTTY yes" \
    >> /etc/ssh/sshd_config

WORKDIR /home/ctf

EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]