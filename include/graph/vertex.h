/** File containing the structure of vertex.
*
* @author gnunes.moura@gmail.com (Gustavo Nunes)
*
*/

#pragma once

#include <vector>
#include <utility>

namespace gnm {

class Edge;

/** 
* @brief Vertex of a graph with N adjacency lists.
*
* Defines the behavior of the class Vertex when it have more than one
* type of adjacency.
* The adjacency lists pointers of Edges.
* 
* Exemple of usage:
*   If you have to calculate the the maximum flow of three diferent things
*   in your system, instead of having three different graphs you can use three
*   adjacency lists on every vertex.
*
* @tparam T Type of the value stored in the Vertex.
* @tparam N Number of diferent kind of adjacencys the vertex may have.
*/
template<class T, std::size_t N>
class Vertex {
public:
    /**
    * @brief Create a Vertex with the desired value stored.
    * 
    * The constructor Vertex recieves a value and stores it using
    * std::move().
    *
    * @param t_value The value that the Vertex will store.
    * @sa std::move()
    */
    Vertex (T t_value) : value(std::move(t_value)),
                            m_adj_lists(N, std::vector<Edge*>()) {}
    
    /**
    * @brief Returns a constant reference one of the adjacecy lists.
    * 
    * 
    *
    */
    const std::vector<Edge*>& adj_list(std::size_t i);

    void add_adj(const Edge* t_adjacency, std::size_t i);

    T value; //< Value strored in the vertex.
private:
    std::vector<std::vector<const Edge*>> m_adj_lists;

};

template<class T>
class Vertex<T, 1> {
public:
    Vertex (T t_value) : value(std::move(t_value)),
                            m_adj_list() {}
    
    T value; //< Value strored in the vertex.
    
    const std::vector<Edge*>& adj_list();

    void add_adj(const Edge* t_adjacency);

private:
    std::vector<const Edge*> m_adj_list;
    
};

}