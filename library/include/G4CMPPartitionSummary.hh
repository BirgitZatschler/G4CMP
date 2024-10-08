/***********************************************************************\
 * This software is licensed under the terms of the GNU General Public *
 * License version 3 or later. See G4CMP/LICENSE for the full license. *
\***********************************************************************/

/// \file library/include/G4CMPPartitionSummary.hh
/// \brief Singleton container class to carry instances of G4CMPPartitionData
///   "hit" data, summarizing the output of G4CMPEnergyPartition.
///   
// $Id$
//
// 20200219  Michael Kelsey (TAMU) <kelsey@slac.stanford.edu>
// 20210131  Move Insert() to .cc file, add clear() action on new event

#ifndef G4CMPPartitionSummary_hh
#define G4CMPPartitionSummary_hh 1

#include "G4ThreadLocalSingleton.hh"
#include "G4CMPPartitionData.hh"	// For client code convenience
#include <vector>


// Provide convenient name for hits container within collection
typedef std::vector<G4CMPPartitionData*> G4CMPPartitionVector;

class G4CMPPartitionSummary {
  friend class G4ThreadLocalSingleton<G4CMPPartitionSummary>;

public:
  static G4CMPPartitionSummary* Instance();		// Singleton object
  virtual ~G4CMPPartitionSummary();

  // Add a new record to the summary table
  static void Insert(G4CMPPartitionData* data) { Instance()->insert(data); }

  // Retrieve specific entry from summary table
  static G4CMPPartitionData* Get(G4int i) { return Instance()->summary[i]; }

  // Retrieve the entire list (e.g., for event processing)
  static const G4CMPPartitionVector& GetSummary() {return Instance()->summary;}

  // Get number of entries
  static size_t Entries() { return Instance()->summary.size(); }

  // Erase all entries in table
  static void Clear() { Instance()->clear(); }

private:
  G4CMPPartitionSummary() : currentEvent(-1) {;}
  void clear();				// Deletes existing table entries
  void insert(G4CMPPartitionData* data); // Adds new record to table
  G4int getEventID();			// Get current event ID
  G4bool isNewEvent();			// Check if new event was started

  G4CMPPartitionVector summary;		// Filled by client code
  G4int currentEvent;			// Keep track of event in progress
};

#endif	/* G4CMPPartitionSummary_hh */
