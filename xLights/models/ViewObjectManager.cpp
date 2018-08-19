#include <wx/xml/xml.h>
#include <wx/msgdlg.h>

#include "ViewObjectManager.h"
#include "GridlinesObject.h"

ViewObjectManager::ViewObjectManager()
{
    //ctor
}

ViewObjectManager::~ViewObjectManager()
{
    //dtor
}

BaseObject* ViewObjectManager::GetObject(const std::string &name) const
{
    return (BaseObject*)GetViewObject(name);
}

ViewObject* ViewObjectManager::GetViewObject(const std::string &name) const
{
    auto it = view_objects.find(name);
    if (it == view_objects.end()) {
        return nullptr;
    }
    return it->second;
}

ViewObject* ViewObjectManager::CreateAndAddObject(const std::string &type) {
    ViewObject *view_object;
    wxXmlNode *node = new wxXmlNode(wxXML_ELEMENT_NODE, "view_object");
    node->AddAttribute("LayoutGroup", "Unassigned");

    std::string name = GenerateObjectName(type);
    node->AddAttribute("name", name);

    if (type == "Gridlines") {
        view_object = new GridlinesObject(node, *this);
    } else {
        wxMessageBox(type + " is not a valid type for View Object " + node->GetAttribute("name"));
        return nullptr;
    }

    AddViewObject(view_object);
    return view_object;
}

void ViewObjectManager::AddViewObject(ViewObject *view_object) {
    if (view_object != nullptr) {
        auto it = view_objects.find(view_object->name);
        if (it != view_objects.end()) {
            delete it->second;
            it->second = nullptr;
        }
        view_objects[view_object->name] = view_object;

        if ("ViewObjectGroup" == view_object->GetDisplayAs()) {
            if (view_object->GetModelXml()->GetParent() != groupNode) {
                if (view_object->GetModelXml()->GetParent() != nullptr) {
                    view_object->GetModelXml()->GetParent()->RemoveChild(view_object->GetModelXml());
                }
                groupNode->AddChild(view_object->GetModelXml());
            }
        } else {
            if (view_object->GetModelXml()->GetParent() != modelNode) {
                if (view_object->GetModelXml()->GetParent() != nullptr) {
                    view_object->GetModelXml()->GetParent()->RemoveChild(view_object->GetModelXml());
                }
                modelNode->AddChild(view_object->GetModelXml());
            }
        }
    }
}

void ViewObjectManager::clear() {
    for (auto it = view_objects.begin(); it != view_objects.end(); ++it) {
        if (it->second != nullptr)
        {
            delete it->second;
            it->second = nullptr;
        }
    }
    view_objects.clear();
}

void ViewObjectManager::LoadViewObjects(wxXmlNode *modelNode) {
    clear();
    this->modelNode = modelNode;
    for (wxXmlNode* e=modelNode->GetChildren(); e!=nullptr; e=e->GetNext()) {
        if (e->GetName() == "model") {
            std::string name = e->GetAttribute("name").ToStdString();
            if (!name.empty()) {
                ViewObject *v = createAndAddObject(e);
            }
        }
    }
}

ViewObject *ViewObjectManager::createAndAddObject(wxXmlNode *node) {
    std::string type = node->GetAttribute("DisplayAs").ToStdString();
    ViewObject *view_object = CreateAndAddObject(type);
    return view_object;
}

std::map<std::string, ViewObject*>::const_iterator ViewObjectManager::begin() const {
    return view_objects.begin();
}

std::map<std::string, ViewObject*>::const_iterator ViewObjectManager::end() const {
    return view_objects.end();
}

unsigned int ViewObjectManager::size() const {
    return view_objects.size();
}

ViewObject *ViewObjectManager::operator[](const std::string &name) const {
    return GetViewObject(name);
}

