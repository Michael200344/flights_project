add_test( [==[USAdata AdjList]==] /workspaces/CS225/flights_project/build/test [==[USAdata AdjList]==]  )
set_tests_properties( [==[USAdata AdjList]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225/flights_project/build)
add_test( [==[AdjList Airport Test]==] /workspaces/CS225/flights_project/build/test [==[AdjList Airport Test]==]  )
set_tests_properties( [==[AdjList Airport Test]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225/flights_project/build)
add_test( [==[BFS Test Level 1]==] /workspaces/CS225/flights_project/build/test [==[BFS Test Level 1]==]  )
set_tests_properties( [==[BFS Test Level 1]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225/flights_project/build)
set( test_TESTS [==[USAdata AdjList]==] [==[AdjList Airport Test]==] [==[BFS Test Level 1]==])
