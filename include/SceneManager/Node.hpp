#ifndef _NODE_HPP_
#define _NODE_HPP_

class Node
{
public:
	Node();
	virtual ~Node();

	virtual void AddChild(Node *addChild);
	virtual void RemoveChild(Node *removeChild);
	virtual void RemoveChild(std::string &node);

	virtual Node *GetParentNode();
	virtual int GetNumberofChildren();

	virtual void SetSize(float size);
	virtual void SetSize(int size);

	virtual void SetPosition(Vector2 &position);
	virtual void SetPoisiton(float x, float y);

	virtual void SetRotation(float angle);

	virtual void SetColour(Colour &colour);

	virtual void SetAlpha(float alpha);

	virtual void SetRenderingDepth(int depth);

	virtual void SetRect(RectT<T> &rect);

	virtual void Render();
	virtual void Update(float deltaT);
protected:
	Node *perviousNode;
	Node *parentNode;
private:
};

#endif // _NODE_HPP_
