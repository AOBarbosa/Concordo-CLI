# Concordo

Concordo is a simple CLI clone of Discord made for the third project of the course Programming Language I, from BTI-UFRN.

## Getting Started

First, clone the project using the following command. Then enter the Concordo file.

```bash
git clone https://github.com/AOBarbosa/Concordo.git
```

### Compilation

```bash
cd Concordo
cd build
cmake ..
make
```

### Starting the program

After compiling the code, you'll have two options:

- Have the full user experience and go step by step, by running the following command

```bash
./program
```

- Run a pre-made script, by running the following command

```bash
./program < script.txt
```

<!-- ### Documentation
If you have installed Doxygen, run `doxygen` on the root directory. Then open
`./docs/html/index.html` with a modern browser. -->

### User Interface

Once you run the program, you'll be faced with an intuitive Command Line Interface. To navigate in the menus, you'll have to digit the desired command.

Example:

```bash
BEM VINDO AO CONCORDO
MAIN MENU
- Para criar usuario, digite: 'create-user <email> <senha_sem_espaços> <nome com espaços>'
- Para fazer login, digite: 'login <email> <senha>'
- Para sair, digite: 'quit'
Digite seu comando:

LOGGED MENU
- Para criar um servidor digite: 'create-server <nome>'
- Para mudar a descrição do servidor atual, digite: 'set-server-desc <nome> <descrição>'
- Para setar código de convite para o servidor, digite: 'set-server-invite-code <nome> <codigo>'
- Para listar os servidores, digite: 'list-servers'
- Para listar pessoas no servidor, digite: 'list-participants'
- Para remover servidor, digite: 'enter-server <nome>'
- Para entrar em um servidor, digite: 'remove-server <nome>'
- Para sair de um servidor, digite: 'leave-server'
- Para listar pessoas no servidor, digite: 'list-participants'
- Para criar um canal, digite: 'create-channel <nome> <tipo>'
- Para entrar em um canal do servidor, digite: 'list-channels'
- Para listar os canais do servidor, digite: 'enter-channel <nome>'
- Para desconectar do Concordo, digite: 'disconnect'
Digite seu comando: 

CHANNELS MENU
- Para enviar uma mensagem para o canal, digite: 'send-message <mensagem>'
- Para visualizar as mensagens do canal, digite: 'list-messages'
Digite o comando:
```

### About the program

Once you start the program you'll face the interfaces above. The first time the user add or change data in the program two new files will be created.

- usuarios.txt

- servidores.txt

Those files will store all data about the users and the servers, respectively.

Every time data gets updated or changed in the program those two files will be updated as well.

The files will be organized in the following format:

- usuarios.txt

  - The first line must have an integer representing the amount of users;

  - In the following lines, for each user there must be 4 lines, one for each user attribute. In this order: id, name, email, password.

- servidores.txt

  - The first line must have an integer representing the amount of servers;

  -  In the following lines, for each server we must have:

      - A line with the user ID of the server owner;

      -  A line with the server name;

      - A line with the server description;

      - A line with the server invitation code (if it's open it must be an empty line);

      - A line with an integer informing the amount of users in the current server;

      - For each participant user in the server there must be a line with it's ID;

      - A line with an integer informing the amount of channels in the current server;

      - For each channel in the server there must be:

          - A line with the channel name;

          - A line with the channel type: "texto" or "voz";

          - A line with an integer representing the amount of messages of the channel;

          - For each message there must be:

              - A line with the ID of the user who wrote it;

              - A line with the current date and time that the message was sent;

              - A line with the message content.

## Limitations

- The program cannot load previous data.

- The main problem with Concordo, it's the memory leaks, wich i couldn't fix.

## Author

- André de Oliveira Barbosa

- Matricula: 20210068204.