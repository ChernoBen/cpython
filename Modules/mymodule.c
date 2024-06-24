#include <Python.h>

static PyObject* mymodule_hello(PyObject* self, PyObject* args) {
    const char* name;
    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;
    printf("Hello, %s!\n", name);
    Py_RETURN_NONE;
}

static PyMethodDef MyModuleMethods[] = {
    {"hello", mymodule_hello, METH_VARARGS, "Print 'Hello, [name]'"},
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
