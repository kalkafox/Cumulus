-- Add path for lua to find the module in ../json/json.lua
local parent_path = "../../"
package.path = package.path .. ";"..parent_path.."json/?.lua;"..parent_path.."?.lua"
-- Load the module
local json = require("json")
local util = require("util")

local alphanumeric = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
local alphanumeric_len = alphanumeric:len()

local function random_string(length)
    local str = ""
    for i = 1, length do
        local index = math.random(1, alphanumeric_len)
        str = str .. alphanumeric:sub(index, index)
    end
    return str
end

local function random_table(depth, max_depth, max_children)
    local t = {}
    local children = math.random(1, max_children)
    for i = 1, children do
        local key = random_string(10)
        local value
        if depth < max_depth then
            value = random_table(depth + 1, max_depth, max_children)
        else
            value = random_string(10)
        end
        t[key] = value
    end
    return t
end

local function test()
    local t = random_table(1, 5, 10)
    local json_str = json.encode(t)
    local decoded = json.decode(json_str)
    util.pt(decoded)
    print("Test passed!")
end

test()
