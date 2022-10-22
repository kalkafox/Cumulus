function table.get_keys(t)
    local keys = {}
    for k, v in pairs(t) do
        table.insert(keys, k)
    end
    return keys
end

-- Based off of the global PrintTable function from Garry's Mod
-- https://github.com/Facepunch/garrysmod/blob/master/garrysmod/lua/includes/util.lua#L59-L93

util = util or {}

function util.print_table(t, indent, style, done)
    indent = indent or 2
    done = done or {}
    style = style or "spaces"

    local keys = table.get_keys(t)

    table.sort(keys, function(a, b)
        if type(a) == "number" and type(b) == "number" then
            return a < b
        else
            return tostring(a) < tostring(b)
        end
    end)

    done[t] = true

    local spacing = string.rep(style == "dots" and "." or " ", indent)

    for i = 1, #keys do
        local key = keys[i]
        local value = t[key]

        local key_type = type(key)
        local value_type = type(value)

        local key_str = key_type == "string" and string.format("%q", key) or tostring(key)
        local value_str = value_type == "string" and string.format("%q", value) or tostring(value)

        if value_type == "table" and not done[value] then
            print(spacing .. key_str .. " = {")
            util.print_table(value, indent + 2, style, done)
            print(spacing .. "}")
        elseif value_type == "function" then
            print(spacing .. key_str .. " = function()")
        else
            print(spacing .. key_str .. " = " .. value_str)
        end
    end
end

util.pt = util.print_table
-- don't sue me garry pls
PrintTable = util.pt

