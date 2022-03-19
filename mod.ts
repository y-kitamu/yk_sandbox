declare var lisp: any;

lisp.defun({
  name: "hello-world",
  docString: "Hello world",
  interactive: true,
  func: () => lisp.print("Hello world!"),
});
