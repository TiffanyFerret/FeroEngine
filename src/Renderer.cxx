void Renderer::requestDraw(Entity* entity,GraphicEntity* gEntity)
{
    mEntityList.push_back(entity);
    mGEntityList.push_back(gEntity);
}
