class Renderer : public Module
{
public:
    void render() = 0;
    void RequestDraw(GraphicEntity*,Entity*);
protected:
    std::vector<GraphicEntity*>mGEntityList;
    std::vector<Entity*>mEntityList
}
