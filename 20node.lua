-- load LÖVE library
love = require("love")
 
-- set up window dimensions
WINDOW_WIDTH = 640
WINDOW_HEIGHT = 480
 
-- set up graph dimensions
GRAPH_WIDTH = 400
GRAPH_HEIGHT = 400
GRAPH_X_OFFSET = 100
GRAPH_Y_OFFSET = 50
 
-- set up number of nodes
NUM_NODES = 20
 
-- set up nodes table
nodes = {}
 
-- initialize random seed
math.randomseed(os.time())
 
-- generate random positions for nodes
for i = 0, NUM_NODES - 1 do
    nodes[i] = {
        x = math.random(GRAPH_WIDTH) + GRAPH_X_OFFSET,
        y = math.random(GRAPH_HEIGHT) + GRAPH_Y_OFFSET
    }
end
 
-- create graph edges
edges = {}
for i = 0, NUM_NODES - 1 do
    for j = i + 1, NUM_NODES - 1 do
        if math.random() < 0.2 then -- probability of edge creation
            table.insert(edges, {i, j})
        end
    end
end
 
-- define LÖVE functions
function love.load()
    love.window.setTitle("Random Graph")
    love.window.setMode(WINDOW_WIDTH, WINDOW_HEIGHT)
end
 
function love.draw()
    -- draw nodes
    love.graphics.setColor(1, 1, 1)
    for i = 0, NUM_NODES - 1 do
        love.graphics.circle("fill", nodes[i].x, nodes[i].y, 5)
    end
 
    -- draw edges
    love.graphics.setColor(1, 0, 0)
    for _, edge in ipairs(edges) do
        local node1 = nodes[edge[1]]
        local node2 = nodes[edge[2]]
        love.graphics.line(node1.x, node1.y, node2.x, node2.y)
    end
end
