<h1 align="center">
	minitalk
</h1>

## Summary
><i>The purpose of this project is to create a communication program in the form of a ``client`` and a ``server``.
</i>

## Getting started
First, clone this repository and `cd` into it:

```zsh
#!/bin/zsh
git clone https://github.com/riceset/minitalk; cd minitalk
```
As this project uses the `libft` you will have to clone it on the root of the repository as well:

```zsh
#!/bin/zsh
git clone https://github.com/dxe58709/libft
```

As this project uses the `ft_printf` you will have to clone it on the root of the repository as well:

```zsh
#!/bin/zsh
git clone https://github.com/dxe58709/printf
```

Compile the executable files with:

```zsh
#!/bin/zsh
make
```

Or use the following command to compile it with the bonus files:
```zsh
#!/bin/zsh
make　bonus
```

## Usage
First, start up the server and it will print a PID:
```zsh
#!/bin/zsh
./server
```
Now you can pass the PID of the server to the client as a command line argument with the message you wish to send:

```zsh
#!/bin/zsh
./client PID "Hello World"
```
