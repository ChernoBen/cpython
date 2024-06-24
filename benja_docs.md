# mymodule.c

- #include <Python.h>: Inclui o cabeçalho principal do Python, que é necessário para trabalhar com a API do Python em um módulo C.

- mymodule_myfunction: Uma função que será exposta como um método do módulo Python. Ela recebe argumentos do Python e retorna um objeto Python.

- PyMethodDef MyModuleMethods[]: Uma lista de métodos do módulo, incluindo o nome do método, a função C correspondente, a forma como os argumentos são passados e uma descrição.

- static struct PyModuleDef mymodulemodule: Uma estrutura que define o módulo Python, incluindo seu nome, métodos e outras informações.

- PyMODINIT_FUNC PyInit_mymodule(void): A função de inicialização do módulo, que é chamada quando o módulo é importado no Python. Ela cria e retorna o objeto de módulo Python.

mymodule.hello
ex:
```
    >>> import mymodule
    >>> print(mymodule)
    <module 'mymodule' (built-in)>
    >>> mymodule.hello('ola')
    Hello, ola!
    >>> quit()
```