add_test( [==[USAdata AdjList Test]==] [==[/workspaces/CS 225/flights_project/build/test]==] [==[USAdata AdjList Test]==]  )
set_tests_properties( [==[USAdata AdjList Test]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225/flights_project/build]==])
add_test( [==[trimList Test NULL]==] [==[/workspaces/CS 225/flights_project/build/test]==] [==[trimList Test NULL]==]  )
set_tests_properties( [==[trimList Test NULL]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225/flights_project/build]==])
add_test( [==[trimList Test]==] [==[/workspaces/CS 225/flights_project/build/test]==] [==[trimList Test]==]  )
set_tests_properties( [==[trimList Test]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225/flights_project/build]==])
add_test( [==[generateSample Test]==] [==[/workspaces/CS 225/flights_project/build/test]==] [==[generateSample Test]==]  )
set_tests_properties( [==[generateSample Test]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225/flights_project/build]==])
set( test_TESTS [==[USAdata AdjList Test]==] [==[trimList Test NULL]==] [==[trimList Test]==] [==[generateSample Test]==])
