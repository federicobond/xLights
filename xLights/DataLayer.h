#ifndef DATALAYER_H
#define DATALAYER_H

#include <wx/string.h>
#include <vector>
#include "SequenceData.h"

class DataLayer
{
    public:
        DataLayer(wxString name, wxString source, wxString data_source);

        virtual ~DataLayer() {};

        wxString GetName() { return mName; }
        void SetName(wxString name) { mName = name; }

        wxString GetSource() { return mSource; }
        void SetSource(wxString source) { mSource = source; }

        wxString GetDataSource() { return mDataSource; }
        void SetDataSource(wxString data_source) { mDataSource = data_source; }

        int GetNumChannels() { return num_channels; }
        void SetNumChannels(int val) { num_channels = val; }

        int GetChannelOffset() { return channel_offset; }
        void SetChannelOffset(int val) { channel_offset = val; }

        int GetNumFrames() { return num_frames; }
        void SetNumFrames(int val) { num_frames = val; }

        int GetLORConvertParams() { return lor_convert_params; }
        void SetLORConvertParams(int val) { lor_convert_params = val; }

        SequenceData& GetSequenceData() { return sequence_data; }

    private:
        wxString mName;
        wxString mSource;
        wxString mDataSource;
        int num_channels;
        int num_frames;
        int channel_offset;
        int lor_convert_params;
        SequenceData sequence_data;
};

class DataLayerSet
{
    public:
        DataLayerSet();
        virtual ~DataLayerSet();

        DataLayer* GetDataLayer(int index);
        void RemoveDataLayer(int index);

        int GetNumLayers() { return mDataLayers.size(); }

        DataLayer* AddDataLayer( wxString name, wxString source, wxString data_source );
        void MoveLayerUp( int index );
        void MoveLayerDown( int index );

    private:
        std::vector<DataLayer*> mDataLayers;
};

#endif // DATALAYER_H
