#include "StdAfx.h"
#include "GraphRendererVisitor.h"

GraphRendererVisitor::GraphRendererVisitor(boost::shared_ptr<SceneGraph> graph) :
	graph_(graph)
{
}

GraphRendererVisitor::~GraphRendererVisitor(void)
{
}

void GraphRendererVisitor::discover_vertex(vertex_descriptor v, const graph_type& g)
{
	boost::shared_ptr<SceneGraphNode> node(graph_->getNode(v));
	node->setState();
	node->draw();
}

void GraphRendererVisitor::finish_vertex(vertex_descriptor v, const graph_type& g)
{
	graph_->getNode(v)->unsetState();
}

