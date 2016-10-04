#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include "LeafWidget.h"
#include "utils.h"


class ImageWidget : public LeafWidget
{
    public:
        /** constructors */
        ImageWidget();
        ImageWidget(const Vector2& position, const Vector2& size);
        ImageWidget(XMLNode* node);

        virtual ~ImageWidget();

        /** properties **/
        string GetSource();
        void SetSource(const string& file);

    protected:
        /** lifecycle hooks **/
        virtual void OnBeforeInitialize();

        /** property change hooks **/
        virtual void OnSetVisible();
        virtual void OnSetPosition();
        virtual void OnSetSize();
        virtual void OnSetSource();

    private:

        string mSource; //!< Member variable "mSource"

        int mSourceImageId; //!< Member variable "mSourceImageId"
        int mSourceSpriteId; //!< Member variable "mSourceSpriteId"
};

#endif // IMAGEWIDGET_H
