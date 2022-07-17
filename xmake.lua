set_languages('c++17')

add_requires('conan::cpputest/4.0', { alias = 'cpputest' })

target('hello')
  set_kind('binary')
  add_files('src/**.cpp')
  add_rules('mode.check', 'mode.release')

target('test')
  set_kind('binary')
  add_files('test/test_runner.cpp')
  add_files('test/src/**.cpp')
  add_includedirs('src/derp')
  add_packages('cpputest')
  add_rules('mode.check')
  after_build(function(target)
    os.exec(target:targetfile())
  end)
