if(EXISTS "/Users/kildman/Mamat_HW/HW62/cmake-build-debug/firewall_test[1]_tests.cmake")
  include("/Users/kildman/Mamat_HW/HW62/cmake-build-debug/firewall_test[1]_tests.cmake")
else()
  add_test(firewall_test_NOT_BUILT firewall_test_NOT_BUILT)
endif()
