# Installation

    git clone git@github.com:matz-e/cms-crab-test.git Crab/Fail
    scram b

# Usage

In your python configuration, add:

    process.fail = cms.EDAnalyzer("Fail")
    process.p = cms.Path(process.fail)

Or use the configuration in `test/pset.py`.
