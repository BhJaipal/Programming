project('dynamic-typed', 'c')

# for C++, uncomment these lines
# add_languages('cpp')
# dynamic = static_library('dynamic', ['./object.cpp'])

dynamic = static_library('dynamic', ['./dict.c', './types.c', './array.c'])

dynamic_dep = declare_dependency(link_whole: [dynamic], include_directories: include_directories('.'))
