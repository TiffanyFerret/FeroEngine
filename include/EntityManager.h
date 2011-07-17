class EntityManager : Module
{
public:
    void addEntity(Entity*);
    void removeEntity(Entity*);
    void drawEntities();
    std::vector<Entity*> *getEntities();
private:
    std::vector<Entity*> *mEntities;
}
