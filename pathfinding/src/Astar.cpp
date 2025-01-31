#include "../include/Astar.h"
#include <queue>
#include <unordered_map>
#include <cmath>
#include <iostream>
#include<cstdio>
#include<stack>

static uint8_t prev_direct;


#define N 0
#define NE 1
#define E 2
#define SE 3
#define S 4
#define SW 5
#define W 6
#define NW 7

struct PointHash {
    size_t operator()(const point& p) const {
        return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
};

struct PointEqual {
    bool operator()(const point& a, const point& b) const {
        return a.x == b.x && a.y == b.y;
    }
};

typedef struct {
    point curr;
    point parent;
    uint8_t direction;
    float g_weight;
    float h_weight;
} meta_data;
typedef struct{
    point location;
    uint8_t direction;
} astar_mouse;

astar_mouse redieeem;

struct Compare {
    bool operator()(const meta_data& a, const meta_data& b) {
        return (a.g_weight + a.h_weight) >æ (b.g_weight + a.h_weight); // Min-queue
    }
};

std::unordered_map<point, meta_data, PointHash, PointEqual> map;
std::priority_queue<meta_data, std::vector<meta_data>, Compare> queue;
std::stack<uint8_t> stack;
point destination;
float Kh = 1;

float get_heuristic(point x) {
    float length = destination.x - x.x;
    float height = destination.y - x.y;
    return Kh * sqrt(length * length + height * height);
}

void executeAction(int relativeDirection) {
    switch (relativeDirection) {
        case 0: // Forward
            API::moveForwardHalf();
            break;
        case 1: // Right 45°
            API::turnRight45();
            API::moveForwardHalf();
            break;
        case 2: // Right 90°
            API::turnRight();
            API::moveForwardHalf();
            break;
        case 3: // Right 135°
            API::turnRight();
            API::turnRight45();
            API::moveForwardHalf();
            break;
        case 4: // Turn around (180°)
            API::turnRight();
            API::turnRight();
            API::moveForwardHalf();
            break;
        case 5: // Left 135°
            API::turnLeft();
            API::turnLeft45();
            API::moveForwardHalf();
            break;
        case 6: // Left 90°
            API::turnLeft();
            API::moveForwardHalf();
            break;
        case 7: // Left 45°
            API::turnLeft45();
            API::moveForwardHalf();
            break;
        default:
            exit(1); // Invalid relative direction
    }
}

void realturn(uint8_t direction) {
    // Compute the relative direction (0-7)
    int relativeDirection = (direction - redieeem.direction + 8) % 8;

    // Execute the corresponding action
    executeAction(relativeDirection);

    // Update the current direction
    redieeem.direction = direction;
}


void Astar(uint8_t x, uint8_t y) {
    redieeem.location.x = mouse.location.x;
    redieeem.location.y = mouse.location.y;
    redieeem.direction = mouse.direction;
    destination.x = x;
    destination.y = y;
    /*
    point curr;
    point parent;
    uint8_t direction;
    float g_weight;
    float h_weight;
    */
    meta_data start = {{1, 1}, {1, 1}, static_cast<uint8_t>(100), 0.0,0.0};
    queue.push(start);
    map[start.curr] = start;
    prev_direct = N;
    uint16_t nodes_explored = 0;
    while (!queue.empty()) {
        meta_data point = queue.top();
        nodes_explored++;
        queue.pop();
        if(point.curr.x == destination.x && point.curr.y == destination.y) break;
        x = point.curr.x;
        y = point.curr.y;
        API::setColor(x/2,y/2,'y');

        auto process_neighbor = [&](int nx, int ny, uint8_t dir) {
            if (nx >= 0 && nx < 33 && ny >= 0 && ny < 33 && maze[nx][ny].visited) {
                meta_data neighbor;
                neighbor.curr = {static_cast<uint8_t>(nx), static_cast<uint8_t>(ny)};
                neighbor.parent = point.curr;
                neighbor.g_weight = point.g_weight + 0.5;
                neighbor.h_weight = get_heuristic(neighbor.curr);
                neighbor.direction = dir;

                if(neighbor.direction != point.direction){
                    neighbor.g_weight += 1;
                }

                if (map.find(neighbor.curr) == map.end() || neighbor.g_weight < map[neighbor.curr].g_weight) {
                    map[neighbor.curr] = neighbor;
                    queue.push(neighbor);
                }
            }
        };

        // Process all neighbors
        process_neighbor(x, y + 1, N);
        process_neighbor(x, y - 1, S);
        process_neighbor(x + 1, y, E);
        process_neighbor(x - 1, y, W);
        process_neighbor(x + 1, y + 1, NE);
        process_neighbor(x - 1, y + 1, NW);
        process_neighbor(x + 1, y - 1, SE);
        process_neighbor(x - 1, y - 1, SW);
    }
    std::cerr<<"A star end"<<std::endl;
    fprintf(stderr,"a star: nodes expanded: %d\n",nodes_explored);
    if (map.find(destination) == map.end()) {
        std::cerr << "No path found to destination." << std::endl;
        return;
    }

    meta_data back_boi = map[destination];
    while (back_boi.curr.x != 1 || back_boi.curr.y != 1) {
        stack.push(back_boi.direction);
        if (map.find(back_boi.parent) == map.end()) {
            std::cerr << "Error: Backtracking failed, parent not found!" << std::endl;
            return;
        }
        back_boi = map[back_boi.parent];
    }
    while(!stack.empty()){
        realturn(stack.top());
        stack.pop();
    }
}
