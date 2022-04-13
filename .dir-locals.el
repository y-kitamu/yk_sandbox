((typescript-mode . ((lsp-enabled-clients . (deno-ls))))
 (c++-mode
  . (
     (lsp-docker+-server-id . ccls)
     (lsp-docker+-docker-server-id . ccls-docker)
     (lsp-docker+-server-command . "ccls")
     (lsp-docker+-image-id . "cpp_engine")
     (lsp-docker+-container-name . "cpp-lsp-docker")
     (lsp-docker+-path-mappings . (("/home/kitamura/work/" . "/home/kitamura/work/")))
     )))
