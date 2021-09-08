#pragma once
#include <boost/shared_ptr.hpp>
#include <pylon/stdinclude.h>
#include <vector>

#ifdef GetFirstChild
#pragma push_macro("GetFirstChild")
#undef GetFirstChild
#define pop_GetFirstChild
#endif

#ifdef GetNextSibling
#pragma push_macro("GetNextSibling")
#undef GetNextSibling
#define pop_GetNextSibling
#endif

namespace tinyxml2
{
    class XMLDocument;
    class XMLNode;
    class XMLAttribute;
};


namespace Pylon
{
    //represents node or attribute.
    class CXmlNode
    {
    public:

        //CXmlAttribute and CXmlNode are implemented in one class, but under the hood attributes and nodes are different.
        //For clearity we use CNodeXml::CAttribute for attributes.
        typedef CXmlNode CXmlAttribute;

        //creates empty node
        CXmlNode();

        //find an attribute of the current node
        CXmlAttribute FindAttribute( const String_t& attribute ) const;
        //'this' will be root, may throws GENICAM EXCEPTIONS
        void LoadFromFile( const String_t& filename );
        //'this' will be root, throws GENICAM EXCEPTIONS
        void LoadFromString( const String_t& xml );

        // Get Name of Node (or Attribute), returns "" if node or attribute is empty
        String_t GetName() const;
        // Get Value/Text Content of Node (or Attribute),returns  "" if node or attribute is empty
        String_t GetContent() const;

        // true if 'this' is empty (invalid or uninitialized). Empty nodes are neither an attribute nor a node, too.
        bool IsEmpty() const;
        // true if 'this' represents an Attribute and is not empty
        bool IsAttribute() const;
        // true if 'this' represents not an Attribute and is not empty
        bool IsNode() const;

        // true if object is a (node or attribute) and not empty.
        operator bool() const;

        //navigate nodes:

        CXmlNode GetRootNode() const;
        //get parent node or empty if not available.
        CXmlNode GetParentNode() const;
        //get first child node or empty if not available.
        CXmlNode GetFirstChild() const;
        //get next sibling or empty if not available.
        CXmlNode GetNextSibling() const;


        // navigate attributes:

        //get first attribute or empty if not available.
        CXmlAttribute GetFirstAttribute() const;
        //get next attribute or empty if not available.
        CXmlAttribute GetNextAttribute() const;

        //get a collection of nodes, does a deep scan starting from 'this' node to all siblings and children
        size_t GetAllNodesWithName( const String_t& name, std::vector<CXmlNode>& nodeList ) const;

        // copy node or attribute
        CXmlNode& operator = ( const CXmlNode& r );
        // copy ctor
        CXmlNode( const CXmlNode& r );
    protected:
         //skip comments and Declarations while enumerating nodes or attributes
        void FilterComments();

        //internal methods to change position, not public . Use Get* instead
        //moves current class to root;
        void ToRoot();
        //moves current class to first child, returns false if no child;
        bool ToFirstChild();
        //moves current class to next sibling, returns false if no next sibling
        bool ToNextSibling();


        // tinyxml pointer
        boost::shared_ptr<tinyxml2::XMLDocument> m_doc;
        tinyxml2::XMLNode* m_currentNode;
        tinyxml2::XMLAttribute* m_currentAttribute;
    };

}


#ifdef pop_GetFirstChild
#pragma pop_macro("GetFirstChild")
#undef pop_GetFirstChild
#endif

#ifdef pop_GetNextSibling
#pragma pop_macro("GetNextSibling")
#undef pop_GetNextSibling
#endif

