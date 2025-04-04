project('logging', 'c')

logging = static_library('logging', ['level.c', 'message.c', 'console-appender.c', 'file-appender.c'])
logging_dep = declare_dependency(link_with: logging, include_directories: include_directories('.'))
