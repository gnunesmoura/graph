#include "graph/vertex.h"

namespace gnm {

    template<class T>
    const std::vector<Edge*>& Vertex<T, 1>::adj_list() {
        return m_adj_list;
    }

    template<class T>
    void Vertex<T, 1>::add_adj(const Edge* t_adjacency) {
        m_adj_list.push_back (t_adjacency);
    }

    template<class T, std::size_t I>
    const std::vector<Edge*>& Vertex<T, I>::adj_list(std::size_t i) {
        return m_adj_lists.at(i);
    }

    template<class T, std::size_t I>
    void Vertex<T, I>::add_adj(const Edge* t_adjacency, std::size_t i) {
        m_adj_lists.at(i).push_back(t_adjacency);
    }

}