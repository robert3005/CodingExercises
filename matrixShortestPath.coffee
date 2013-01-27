#!/usr/bin/env coffee
http = require 'http'

# Takes function which maps elements stored in the heap to their score
# reduce of (x) -> x gives Min Heap of numbers
# reduce of (x) -> -x gives Max Heap of numbers
class Heap

	constructor: (@reduce) ->
		@contents = []

	peek: ->
		if not @isEmpty()
			@contents[0]

	pop: ->
		if not @isEmpty()
			res = @contents[0]
			last = @contents.pop()
			if @contents.length > 0
				@contents[0] = last
				@heapify 0
			return res
		else
			return null

	push: (element) ->
		@contents.push element
		@bubbleUp @contents.length - 1

	heapify: (idx) ->
		numElem = @contents.length
		if numElem > 2 * idx + 1
			child = 2 * idx + 1
			if numElem > child + 1 && @contents[child + 1]?
				rightChild = child + 1
				if @reduce(@contents[rightChild]) < @reduce(@contents[child])
					child = rightChild

			if @reduce(@contents[idx]) > @reduce(@contents[child])
				@swap idx, child
			@heapify 2*idx+1
			@heapify 2*idx+2

	bubbleUp: (idx) ->
		if idx > 0
			parentIdx = Math.floor( ( idx + 1 ) / 2 ) - 1
			if @reduce(@contents[idx]) < @reduce(@contents[parentIdx])
				@swap idx, parentIdx
				@bubbleUp parentIdx

	isEmpty: ->
		@contents.length == 0

	swap: (i, j) ->
		temp = @contents[i]
		@contents[i] = @contents[j]
		@contents[j] = temp

class GraphNode

	constructor: (@id, @x, @y) ->
		@adjacentNodes = []

	addEdge: (destNode, weight) ->
		adjEntry =
			node: destNode
			weight: weight
		@adjacentNodes.push adjEntry

class MatrixMinPath

	constructor: (@JSONMatrix) ->

	validate: ->
		try
			matrixObj = JSON.parse @JSONMatrix
		catch e
			return [false, "Input is not a properly formatted JSON"]

		if not matrixObj.matrix?
			return [false, "Input has to have \"matrix\" field"]

		@matrix = matrixObj.matrix
		if not Array.isArray @matrix
			return [false, "Input to the program has to be an array"]

		columnHeight = @matrix[0].length
		correctLength = true
		@matrix.forEach (row, rowNum) ->
			if not (row.length is columnHeight)
				correctLength = false

		if not correctLength
			return [false, "Input is not a properly formatted matrix"]

		return [true, "Proper input"]

	topBottomPath: ->
		[graph, dest] = @matrixToGraph()
		@shortestPath graph, dest

	matrixToGraph: ->
		lastId = 0
		uniqueId = ->
			lastId++
		# Create start node
		s = new GraphNode uniqueId(), -1, -1
		# Change matrix numbers to graph nodes
		matrixToNodes = @matrix.map (row, rowNum) ->
							row.map (cell, colNum) ->
								new GraphNode uniqueId(), rowNum, colNum
		# Add top node successors
		matrixToNodes[0].forEach (topNode, idx) =>
			s.addEdge topNode, @matrix[topNode.x][topNode.y]

		possibleChildren = (col, row) =>
			children = []
			if row < @matrix.length - 1
				if col > 0
					children.push [col - 1, row + 1]
				if col < @matrix[0].length - 1
					children.push [col + 1, row + 1]
				children.push [col, row + 1]
			children

		# Add edges to the graph for each node in the graph
		matrixToNodes.forEach (row, rowNum) =>
			row.forEach (cell, colNum) =>
				cell.addEdge matrixToNodes[y][x], @matrix[y][x] for [x, y] in possibleChildren colNum, rowNum

		f = new GraphNode uniqueId(), @matrix.length, @matrix[0].length

		# Add finish node to the graph
		matrixToNodes[matrixToNodes.length - 1].forEach (bottomNode, idx) ->
			bottomNode.addEdge f, 0

		# Return list of all nodes shortest path finding algorithm
		flatNodeList = [s]
		Array.prototype.push.apply flatNodeList, row for row in matrixToNodes
		flatNodeList.push f

		return [flatNodeList, f.id]

	shortestPath: (graph, destination) ->
		# Performs shortest path search from node 0 to node destination. Start node must be first one in the list.
		MAX_INT = 4294967295;
		distance = [0]
		distance.push MAX_INT for x in [1..destination]
		queue = new Heap (x) -> distance[x.id]
		queue.push v for v in graph
		while not queue.isEmpty()
			minNode = queue.peek()
			minNode.adjacentNodes.forEach (adj) ->
				if distance[adj.node.id] > distance[minNode.id] + adj.weight
					distance[adj.node.id] = distance[minNode.id] + adj.weight
			queue.pop()

		distance[destination]

if not module.parent
	http.createServer((req, res) ->
		if req.method is 'POST'
			requestData = ""
			req.on 'data', (chunk) ->
				requestData += chunk
			req.on 'end', ->
				matrixGraph = new MatrixMinPath requestData
				[valid, message] = matrixGraph.validate()
				if not valid
					console.log message
					res.writeHead 400
					res.end message + "\n"
				else
					weight = matrixGraph.topBottomPath()
					res.writeHead 200
					res.end "Weight: " + weight + "\n"
		else
			res.writeHead 400
			res.end "Only POST requests are supported\n"
	).listen 3000
else
	module.exports = exports = MatrixMinPath: MatrixMinPath