#ifndef AVHRRSATELLITE_H
#define AVHRRSATELLITE_H

#include <QObject>
#include <QMessageBox>
#include <QtXml>

#include "satellite.h"
#include "segmentmetop.h"
#include "segmentnoaa.h"
#include "segmenthrp.h"
#include "segmentgac.h"
#include "segmentviirsm.h"
#include "segmentviirsdnb.h"
#include "segmentolci.h"
#include "segmenthrpt.h"
#include "segmentslstr.h"
#include "segmentdatahub.h"

#include "segmentlistmetop.h"
#include "segmentlistnoaa.h"
#include "segmentlisthrp.h"
#include "segmentlistgac.h"
#include "segmentlistgeostationary.h"
#include "segmentlistviirsm.h"
#include "segmentlistviirsdnb.h"
#include "segmentlistolci.h"
#include "segmentlisthrpt.h"
#include "segmentlistslstr.h"
#include "segmentlistdatahub.h"
#include "datahubaccessmanager.h"

#include "segmentimage.h"
#include "options.h"

class SegmentList;
class SegmentListGeostationary;
class SegmentListNoaa;
class SegmentListMetop;
class SegmentListHRP;
class SegmentListGAC;
class SegmentListVIIRSM;
class SegmentListVIIRSDNB;
class SegmentListOLCI;
class SegmentListSLSTR;
class SegmentListHRPT;
class SegmentListDatahub;


class AVHRRSatellite  : public QObject
{
    Q_OBJECT

public:
    AVHRRSatellite(QObject *parent = 0, SatelliteList *lst = 0);
    void ReadDirectories(QDate seldate, int hoursbefore);
    void AddSegmentsToList(QFileInfoList fileinfolist);
    SegmentListGeostationary *getActiveSegmentList();
    bool SelectedAVHRRSegments();
    bool SelectedVIIRSMSegments();
    bool SelectedVIIRSDNBSegments();
    bool SelectedOLCIefrSegments();
    bool SelectedOLCIerrSegments();
    bool SelectedSLSTRSegments();

    void RemoveAllSelectedAVHRR();
    void RemoveAllSelectedVIIRSM();
    void RemoveAllSelectedVIIRSDNB();
    void RemoveAllSelectedOLCIefr();
    void RemoveAllSelectedOLCIerr();
    void RemoveAllSelectedSLSTR();
    void RemoveAllSelectedDatahubOLCIefr();
    void RemoveAllSelectedDatahubOLCIerr();
    void RemoveAllSelectedDatahubSLSTR();

    void emitProgressCounter(int);

    QString GetOverviewSegments();
    QStringList GetOverviewSegmentsMetop();
    QStringList GetOverviewSegmentsNoaa();
    QStringList GetOverviewSegmentsGAC();
    QStringList GetOverviewSegmentsHRP();

    QStringList GetOverviewSegmentsMetopAhrpt();
    QStringList GetOverviewSegmentsMetopBhrpt();
    QStringList GetOverviewSegmentsNoaa19hrpt();
    QStringList GetOverviewSegmentsM01hrpt();
    QStringList GetOverviewSegmentsM02hrpt();

    QStringList GetOverviewSegmentsVIIRSM();
    QStringList GetOverviewSegmentsVIIRSDNB();
    QStringList GetOverviewSegmentsOLCIefr();
    QStringList GetOverviewSegmentsOLCIerr();
    QStringList GetOverviewSegmentsSLSTR();

    QStringList GetOverviewSegmentsDatahubOLCIefr();
    QStringList GetOverviewSegmentsDatahubOLCIerr();
    QStringList GetOverviewSegmentsDatahubSLSTR();

    QStringList GetOverviewSegmentsGeo(int geoindex);



    void drawOverlay(char *pFileName );
    bool getShowAllSegments() { return showallsegments; }
    void setShowAllSegments(bool allseg) { showallsegments = allseg; }

    void LoadXMLfromDatahub();
    void ReadXMLfiles();
    void setXMLDate(QDate date) { xmlselectdate = date; }
    void setAbsolutePathFromMap(int geoindex, QString strdate);


    SegmentListMetop *seglmetop;
    SegmentListNoaa *seglnoaa;
    SegmentListHRP *seglhrp;
    SegmentListGAC *seglgac;
    SegmentListVIIRSM *seglviirsm;
    SegmentListVIIRSDNB *seglviirsdnb;
    SegmentListOLCI *seglolciefr;
    SegmentListOLCI *seglolcierr;
    SegmentListSLSTR *seglslstr;
    SegmentListHRPT *seglmetopAhrpt;
    SegmentListHRPT *seglmetopBhrpt;
    SegmentListHRPT *seglnoaa19hrpt;
    SegmentListHRPT *seglM01hrpt;
    SegmentListHRPT *seglM02hrpt;
    SegmentListDatahub *segldatahubolciefr;
    SegmentListDatahub *segldatahubolcierr;
    SegmentListDatahub *segldatahubslstr;

    QList<SegmentListGeostationary *> seglgeo;
    QList<QMap<QString, QMap<QString, QMap< int, QFileInfo > > > > segmentlistmapgeo;


private:

    void InsertToMap(QFileInfoList fileinfolist, QMap<QString, QFileInfo> *map, bool *noaaTle, bool *metopTle, bool *nppTle, bool *sentinel3Tle, QDate seldate, int hoursbefore);
    void RemoveFromList(QList<Segment*> *sl);
    void CreateListfromXML(QDomDocument document);
    void getFilenameParameters(int geosatindex, QString filename, QString &strspectrum, QString &strdate, int &filenbr);

    DatahubAccessManager hubmanager;
    QDate xmlselectdate;
    SatelliteList *satlist;
    long nbrofpointsselected;
    long countmetop;
    long countnoaa;
    long counthrp;
    long countgac;
    long countviirsm;
    long countviirsdnb;
    long countviirsmdnb;
    long countolciefr;
    long countolcierr;
    long countslstr;
    long countmetopAhrpt;
    long countmetopBhrpt;
    long countnoaa19hrpt;
    long countM01hrpt;
    long countM02hrpt;
    long countdatahubolciefr;
    long countdatahubolcierr;
    long countdatahubslstr;

    bool showallsegments;

signals:
    void signalProgress(int progress); // in formephem
    void signalResetProgressbar(int max, const QString &text);
    void signalAddedSegmentlist(void);
    void signalShowSegmentCount(void);
    //void signalMeteosatSegment(QString, QString, int);
    void progressCounter(int);
    void signalXMLProgress(QString, int, bool);

private slots:
    void XMLFileDownloaded();
    void XMLPagesDownloaded(int pages);

public slots:
    void AddSegmentsToListFromUdp(QByteArray thefilepath);

};


#endif // AVHRRSATELLITE_H
