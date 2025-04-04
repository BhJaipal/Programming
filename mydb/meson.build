project('mydb', 'c')

src = ['./table.c', './table-attr.c', './table-data.c', './table-rows.c', './data-dict.c']

dynamic_dep = subproject('dynamic-typed').get_variable('dynamic_dep')
logging = subproject('logging').get_variable('logging_dep')
deps = [ dynamic_dep, logging ]

mydb = shared_library('mydb', src, dependencies: deps, include_directories: include_directories('.'))

executable('demo', './demo.c', link_with: mydb, dependencies: deps)
