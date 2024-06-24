#include <Python.h>

static PyObject* mymodule_hello(PyObject* self, PyObject* args) {
    const char* name;
    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;
    printf("Hello, %s!\n", name);
    Py_RETURN_NONE;
}

static PyObject* mymodule_myfunction(PyObject* self, PyObject* args) {
    const char* input;
    
    // Parse the input arguments
    if (!PyArg_ParseTuple(args, "s", &input)) {
        return NULL;
    }
    
    // Perform some operation
    printf("Received: %s\n", input);
    
    // Return a Python object (if needed)
    return PyLong_FromLong(strlen(input));
}

static PyObject* mymodule_print_var_info(PyObject* self, PyObject* args) {
    PyObject* var;

    // Parse the input arguments
    if (!PyArg_ParseTuple(args, "O", &var)) {
        return NULL;
    }

    // Get the type of the variable
    const char* type = Py_TYPE(var)->tp_name;

    // Get the memory address of the variable
    unsigned long address = (unsigned long)var;

    // Print the type and address
    printf("Variable type: %s\n", type);
    printf("Memory address: %p\n", (void*)address);

    Py_RETURN_NONE;
}


static PyMethodDef MyModuleMethods[] = {
    {"hello", mymodule_hello, METH_VARARGS, "Print 'Hello, [name]'"},
    {"myfunction", mymodule_myfunction, METH_VARARGS, "A function that takes a string argument."},
    {"print_var_info", mymodule_print_var_info, METH_VARARGS, "A function that prints the type and memory address of a variable."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT,
    "mymodule",
    NULL,
    -1,
    MyModuleMethods
};

PyMODINIT_FUNC PyInit_mymodule(void) {
    return PyModule_Create(&mymodule);
}
