project('c-templates',
  ['c'],
  version : '0.1',
  default_options : ['warning_level=3', 'werror=true'])

include = include_directories('./include')

test('test_vector',
  executable('test_vector',
    ['tests/vector.c'],
    include_directories: include))

test('test_map',
  executable('test_map',
    ['tests/map.c'],
    include_directories: include))
