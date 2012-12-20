MatrixMinPath = require('./matrixShortestPath.coffee').MatrixMinPath
should = require 'should'

matrixTest = (matrix, expected) ->
	matrixGraph = new MatrixMinPath matrix
	[valid, message] = matrixGraph.validate()
	valid.should.be.true
	matrixGraph.topBottomPath().should.equal expected

describe 'min path tests', ->
	it 'ordered test case', ->
		matrixTest '{ "matrix": [ [1,2,3], [4,5,6], [7,8,9] ] }', 12
	it 'given test case', ->
		matrixTest '{ "matrix": [ [3,1,4], [1,5,9], [2,6,5] ] }', 4
	it 'anit greedy', ->
		matrixTest '{ "matrix": [ [100,100,1,1], [1000,1000,1000,1], [0,1,10000,10000], [1,10000,1,1] ] }', 1002
	it 'larger test', ->
		matrixTest '{ "matrix": [ [3,1,5,6,7], [8,11,30,6,0], [10,9,17,4,5], [18,22,21,15,17], [9,4,5,7,40], [25,0,25,0,25] ] }', 30