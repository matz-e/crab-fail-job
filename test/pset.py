import FWCore.ParameterSet.Config as cms

process = cms.Process('DestinedToFail')

process.source = cms.Source("PoolSource", fileNames=cms.untracked.vstring())
process.output = cms.OutputModule(
    "PoolOutputModule",
    outputCommands=cms.untracked.vstring(
        "drop *",
        "keep FEDRawDataCollection_*_*_*",
        "keep recoTracks_*_*_*"
    ),
    fileName=cms.untracked.string('output.root'),
)
process.out = cms.EndPath(process.output)

process.fail = cms.EDAnalyzer("Fail", jobid=cms.string("1"), retries=cms.int32(2))
process.p = cms.Path(process.fail)
