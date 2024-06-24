FROM ubuntu:latest

# Atualizar e instalar dependências
RUN apt-get update && apt-get install -y \
    build-essential \
    zlib1g-dev \
    libncurses5-dev \
    libgdbm-dev \
    libnss3-dev \
    libssl-dev \
    libreadline-dev \
    libffi-dev \
    curl \
    libbz2-dev \
    wget

# Adicionar um usuário não root
RUN useradd -ms /bin/bash myuser
USER myuser
WORKDIR /home/myuser

# Copiar o código fonte do CPython para o container
COPY --chown=myuser:myuser . cpython
WORKDIR /home/myuser/cpython

# Configurar e compilar o CPython
RUN ./configure 
RUN make 

# Definir o ponto de entrada
ENTRYPOINT ["./python"]
