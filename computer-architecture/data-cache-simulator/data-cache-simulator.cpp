/***********************************************************
* Name: Ariel Wundke
* Class: CDA3100
* Assignment: Implementing a Data Cache Simulator (C++ version, safe)
* Compile: g++ -std=c++11 -o datacache datacache.cpp
***********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

struct CacheLine {
    bool valid = false;
    bool dirty = false;
    unsigned int tag = 0;
    int lru_counter = 0; // 0 = most recently used
};

struct CacheSet {
    vector<CacheLine> lines;
};

struct Cache {
    int num_sets;
    int set_size;
    int line_size;
    int offset_bits;
    int index_bits;
    vector<CacheSet> sets;
};

// Global statistics
int total_hits = 0, total_misses = 0, total_accesses = 0;

// Compute log2 for powers of 2
int log2_int(int x) {
    return (int)log2(x);
}

// Initialize cache
void init_cache(Cache& cache, int num_sets, int set_size, int line_size) {
    cache.num_sets = num_sets;
    cache.set_size = set_size;
    cache.line_size = line_size;
    cache.offset_bits = log2_int(line_size);
    cache.index_bits = log2_int(num_sets);
    cache.sets.resize(num_sets);
    for (int i = 0; i < num_sets; ++i)
        cache.sets[i].lines.resize(set_size);
}

// Update LRU counters after access
void update_lru(CacheSet& set, int accessed_index, int set_size) {
    int old_counter = set.lines[accessed_index].lru_counter;
    for (int i = 0; i < set_size; ++i) {
        if (set.lines[i].valid && set.lines[i].lru_counter < old_counter)
            set.lines[i].lru_counter++;
    }
    set.lines[accessed_index].lru_counter = 0;
}

// Simulate cache access
bool access_cache(Cache& cache, char type, unsigned int addr, int& memrefs) {
    int index = (addr >> cache.offset_bits) & (cache.num_sets - 1);
    unsigned int tag = addr >> (cache.offset_bits + cache.index_bits);
    CacheSet& set = cache.sets[index];

    // Check for hit
    for (int i = 0; i < cache.set_size; ++i) {
        if (set.lines[i].valid && set.lines[i].tag == tag) {
            update_lru(set, i, cache.set_size);
            if (type == 'W') set.lines[i].dirty = true;
            memrefs = 0;
            return true;
        }
    }

    // Miss
    total_misses++;
    memrefs = 1;

    // Find LRU line
    int lru_index = 0;
    int max_counter = -1;
    for (int i = 0; i < cache.set_size; ++i) {
        if (!set.lines[i].valid) { lru_index = i; break; }
        if (set.lines[i].lru_counter > max_counter) {
            max_counter = set.lines[i].lru_counter;
            lru_index = i;
        }
    }

    // Write back if dirty
    if (set.lines[lru_index].valid && set.lines[lru_index].dirty)
        memrefs++;

    // Fill cache line
    set.lines[lru_index].valid = true;
    set.lines[lru_index].dirty = (type == 'W');
    set.lines[lru_index].tag = tag;
    update_lru(set, lru_index, cache.set_size);

    return false;
}

int main() {
    Cache cache;

    // Read cache config
    ifstream config("trace.config");
    if (!config) { cerr << "Cannot open trace.config\n"; return 1; }
    int num_sets, set_size, line_size;
    string line;
    getline(config, line); num_sets = stoi(line.substr(line.find(":") + 1));
    getline(config, line); set_size = stoi(line.substr(line.find(":") + 1));
    getline(config, line); line_size = stoi(line.substr(line.find(":") + 1));
    config.close();

    init_cache(cache, num_sets, set_size, line_size);

    // Print cache configuration
    cout << "Cache Configuration\n";
    cout << num_sets << " " << set_size << "-way set associative entries\n";
    cout << "of line size " << line_size << " bytes\n\n";

    cout << "Results for Each Reference\n";
    cout << left;
    cout << setw(4) << "Ref"
        << setw(8) << "Access"
        << setw(10) << "Address"
        << setw(8) << "Tag"
        << setw(6) << "Index"
        << setw(8) << "Offset"
        << setw(8) << "Result"
        << setw(7) << "Memrefs" << "\n";

    cout << "---- ------ -------- ------- ----- ------ -------\n";

    // Read trace
    ifstream trace("trace.dat");
    if (!trace) { cerr << "Cannot open trace.dat\n"; return 1; }

    int ref_num = 0;
    while (getline(trace, line)) {
        ref_num++;
        if (line.empty()) continue;

        char type;
        unsigned int addr;
        int size;
        sscanf(line.c_str(), "%c:%d:%x", &type, &size, &addr);

        if (!(size == 1 || size == 2 || size == 4 || size == 8) || addr % size != 0) {
            cerr << "Warning: Invalid reference size or alignment at ref " << ref_num << "\n";
            continue;
        }

        total_accesses++;
        int memrefs;
        bool hit = access_cache(cache, type, addr, memrefs);
        if (hit) total_hits++;

        int offset = addr & (line_size - 1);
        int index = (addr >> cache.offset_bits) & (num_sets - 1);
        unsigned int tag = addr >> (cache.offset_bits + cache.index_bits);

        cout << setw(4) << ref_num
            << setw(8) << (type == 'R' ? "read" : "write")
            << setw(10) << hex << addr
            << setw(8) << tag
            << setw(6) << dec << index
            << setw(8) << offset
            << setw(8) << (hit ? "hit" : "miss")
            << setw(7) << memrefs
            << "\n";
    }

    trace.close();

    cout << "\nSimulation Summary Statistics\n";
    cout << "-----------------------------\n";
    cout << "Total hits : " << total_hits << "\n";
    cout << "Total misses : " << total_misses << "\n";
    cout << "Total accesses : " << total_accesses << "\n";
    cout << "Hit ratio : " << fixed << double(total_hits) / total_accesses << "\n";
    cout << "Miss ratio : " << fixed << double(total_misses) / total_accesses << "\n";

    return 0;
}
